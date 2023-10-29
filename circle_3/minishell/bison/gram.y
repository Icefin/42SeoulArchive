%token WORD
%token SLESS
%token SGREAT
%token DLESS
%token DGREAT
%token PIPE

%start pipe_sequence
%%
cmd_name	: WORD
			;
cmd_word	: WORD
			;
filename	: WORD
			;
here_end	: WORD
			;

io_file		: SLESS		filename
			| SGREAT	filename
			| DGREAT	filename
			;
io_here		: DLESS		here_end
			;
io_redirect	: io_file
			| io_here
			;

cmd_prefix	: io_redirect
			| cmd_prefix	io_redirect
			;
cmd_suffix	: io_redirect
			| cmd_suffix	io_redirect
			| WORD
			| cmd_suffix	WORD
			;
simple_command	: cmd_prefix	cmd_word	cmd_suffix
				| cmd_prefix	cmd_word
				| cmd_prefix
				| cmd_name	cmd_suffix
				| cmd_name
				;

pipe_sequence	: simple_command
				| pipe_sequence PIPE simple_command
				;

%%