from yt_dlp import YoutubeDL

playlist_url = "https://youtube.com/playlist?list=PLBlnK6fEyqRjNMcnL9EeVp5bnWXBgeIfB&si=yWr-9dZKs2DtZCfA"

ydl_opts = {
    "quiet": True,
    "extract_flat": True,
}

seen = set()

with YoutubeDL(ydl_opts) as ydl:
    playlist_info = ydl.extract_info(playlist_url, download=False)

    with open("unique_playlist_urls.txt", "w", encoding="utf-8") as f:
        for video in playlist_info["entries"]:
            video_id = video.get("id")

            if video_id in seen:
                continue

            seen.add(video_id)
            f.write(f"https://www.youtube.com/watch?v={video_id}\n")

print(f"Saved {len(seen)} unique video URLs to unique_playlist_urls.txt")