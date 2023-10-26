//Backus-Naur form

cmd_name		: WORD
			;			/*Apply rule 1*/
cmd_word		: WORD
			;			/*Apply rule 1*/
filename		: WORD
			;			/*Apply rule 2*/
here_end		: WORD
			;			/*Apply rule 3*/

io_file			: SLESS		filename
			| SGREAT	filename
			| DGREAT	filename
			;
io_here			: DLESS		here_end
			;
io_redirect		: io_file
			| io_here
			;

cmd_prefix		: io_redirect
			| cmd_prefix	io_redirect
			;
cmd_suffix		: io_redirect
			| cmd_suffix	io_redirect
			| WORD
			| cmd_suffix	WORD
			;
simple_command		: cmd_prefix	cmd_word	cmd_suffix
			| cmd_prefix	cmd_word
			| cmd_prefix
			| cmd_name	cmd_suffix
			| cmd_name
			;

pipe_sequence		: simple_command
			| pipe_sequence PIPE simple_command
			;