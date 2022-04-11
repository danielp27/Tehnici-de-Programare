X=1
git push --set-upstream origin main

while true; do
    git add *.c >/dev/null 2>/dev/null
    git add *.txt >/dev/null 2>/dev/null
    git add *.bat >/dev/null 2>/dev/null
    git add *.sh >/dev/null 2>/dev/null
    git commit -m "auto push $X"
    git push

    X=`expr $X + 1`
    echo Punct. Si de la capat...

    sleep 150
done
