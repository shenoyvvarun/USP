#ls -l | sed '1d'
# sed : stream editor  d:delete 1:first line
# remove multiple white spaces
#ls -l | sed '1d' | tr -s " "
# pickup a few col
#ls -l | sed '1d' | tr -s " " | cut -d" " -f5,9
# sort
#ls -l | sed '1d' | tr -s " " | cut -d" " -f5,9 | sort -n -r
# pickup the first line
ls -l | sed '1d' | tr -s " " | cut -d" " -f5,9 | sort -n -r |  tee out | head -1

# cmd1 | cmd2 | cmd3 | ...  | cmd n - 1 | cmd n

# filters : take input from stdin; output to stdout
#	cmd2 .. cmd n-1 should be filters
