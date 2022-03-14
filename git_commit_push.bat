git push --set-upstream origin main
git add *.c >NUL 2>NUL
git add *.cpp >NUL 2>NUL
git add *.txt >NUL 2>NUL
git add *.bat >NUL 2>NUL
echo "Commit message: "
git commit -m "%msg%"
git push
	

