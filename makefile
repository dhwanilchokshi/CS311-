all:
	gcc machine.c -o machine 
	./machine test_fail.in & ./machine test_pass.in
