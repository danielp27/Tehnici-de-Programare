#!/bin/sh

git push --set-upstream origin main
git add *.c >/dev/null 2>/dev/null
git add *.cpp >/dev/null 2>/dev/null
git add *.txt >/dev/null 2>/dev/null
git add *.bat >/dev/null 2>/dev/null
git add *.sh >/dev/null 2>/dev/null
echo -n "Commit message: "
read msg
git commit -m "$msg"
git push
