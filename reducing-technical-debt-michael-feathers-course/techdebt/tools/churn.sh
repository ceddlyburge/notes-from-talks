find . -name "*.rb" |xargs -n1 -I file sh -c 'echo `git log --oneline file | wc -l`: file'|sort -nr
