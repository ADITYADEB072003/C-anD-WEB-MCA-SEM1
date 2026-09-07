from pathlib import Path
import subprocess

import certifi
from yt_dlp import YoutubeDL

# YouTube Playlist URL
PLAYLIST_URL = "https://youtube.com/playlist?list=PLBlnK6fEyqRhclwDR4oSl8lRSaEpkxQn9&si=b3A5N5-OnR0h1mpr"

# LaunchAgents cannot reliably access macOS's protected Documents folder. Keep
# its persistent data in the user's Application Support folder instead.
DATA_DIR = Path.home() / "Library" / "Application Support" / "PlaylistChecker"
DATA_DIR.mkdir(parents=True, exist_ok=True)
OUTPUT_FILE = DATA_DIR / "playlist_urls.txt"

ydl_opts = {
    "quiet": True,
    "extract_flat": True,
    "ca_certs": certifi.where(),
}

# Read existing URLs
existing_urls = set()

if OUTPUT_FILE.exists():
    with OUTPUT_FILE.open("r", encoding="utf-8") as f:
        existing_urls = {line.strip() for line in f if line.strip()}

# Get playlist videos
with YoutubeDL(ydl_opts) as ydl:
    playlist = ydl.extract_info(PLAYLIST_URL, download=False)

new_urls = []

seen = set()

for video in playlist["entries"]:
    video_id = video.get("id")

    if not video_id or video_id in seen:
        continue

    seen.add(video_id)

    url = f"https://www.youtube.com/watch?v={video_id}"

    if url not in existing_urls:
        new_urls.append(url)

# Append only new videos
if new_urls:
    with OUTPUT_FILE.open("a", encoding="utf-8") as f:
        for url in new_urls:
            f.write(url + "\n")

    print(f"Added {len(new_urls)} new video(s):")
    for url in new_urls:
        print(url)

    # macOS desktop notification.  Escape strings before embedding them in
    # AppleScript so playlist text cannot break the command.
    count = len(new_urls)
    message = f"{count} new video{'s' if count != 1 else ''} added to your playlist."
    apple_script = (
        'display notification "'
        + message.replace('"', '\\"')
        + '" with title "YouTube playlist updated"'
    )
    try:
        subprocess.run(["osascript", "-e", apple_script], check=True)
    except (OSError, subprocess.CalledProcessError) as error:
        # Finding videos must still work if notifications are unavailable.
        print(f"Could not display notification: {error}")
else:
    print("No new videos found.")
