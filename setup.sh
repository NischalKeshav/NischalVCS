#setup with tmux 
SESH="NVCS"
tmux has-session -t $SESH 2> /dev/null

if [ $? != 0 ]; then
	#primary editor
	tmux new-session -d -s $SESH -n "editor"
	tmux send-keys -t $SESH:editor "cd ~/Desktop/Coding/mygit" C-m
	tmux send-keys -t $SESH:editor "nvim ./" C-m
	
	#testing environment
	tmux split-window -h -t $SESH:editor
	tmux send-keys -t $SESH:editor.1 "cd ~/NVCStesting/day6" C-m
fi

tmux attach-session -t $SESH	

