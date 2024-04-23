ram:	ram.o 
	qld -o ram ram.o 

ram2:	ram.o
	qld -o ram2 -screspr_o ram.o 

ram.o:	ram.c
		@echo $(PATH)
		qcc -o ram.o -c ram.c
		qcc -S ram.c

clean:
	rm -f ram.o

cleaner:	clean
	rm -f ram

deploy:	ram
	cp ram /home/simon/emulators/ql/emulators/sQLux/flp1

run:   	deploy
	cd /home/simon/emulators/ql/emulators/sQLux && ./sqlux --SPEED=0.95 --RAMSIZE=256 --SOUND 8 -b "OPEN #8,con_512x256a0x0_0:CLS #8:INK #8,4:EW flp1_ram,#8"

runfast:   	deploy
	cd /home/simon/emulators/ql/emulators/sQLux && ./sqlux --SPEED=10 --RAMSIZE=256 --SOUND 8 -b "OPEN #8,con_512x256a0x0_0:CLS #8:INK #8,4:EW flp1_ram,#8"

dist:	deploy
	qltools ram.img -fdd ram -W
	qltools ram.img -W ram
	
