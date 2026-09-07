#!/bin/zsh
# launchd uses a minimal PATH; include the usual Homebrew locations.
export PATH="/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin"

APP_DIR="$HOME/Library/Application Support/PlaylistChecker"
cd "$APP_DIR"
exec "$APP_DIR/.venv/bin/python" play2.py
