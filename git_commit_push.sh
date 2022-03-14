git push --set-upstream origin main
git add *.c >NUL 2>NUL
git add *.cpp >NUL 2>NUL
git add *.txt >NUL 2>NUL
git add *.bat >NUL 2>NUL
git add *.sh >NUL 2>NUL
read -p 'Commit message: ' msg
git commit -m $msg
git push 
	

