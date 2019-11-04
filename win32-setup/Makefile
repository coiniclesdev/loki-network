# Makefile for windows install pkg and helper library

CC=i686-w64-mingw32-gcc
CXX=i686-w64-mingw32-g++
CFLAGS=-Ofast -march=nocona -mfpmath=sse
LIBS=-lws2_32
LDFLAGS=-static

all: regdbhelper.dll lokinet-bootstrap.exe 7z.exe dbghelp tcpv6 tap-win32
default: all

ifndef RELEASE
regdbhelper.dll:
	i686-w64-mingw32-gcc regdb_helper.c -o $@ -shared -Os -s

mbedtls:
	wget https://tls.mbed.org/download/mbedtls-2.16.3-apache.tgz
	tar xvf mbedtls-2.16.3-apache.tgz
	patch -p0 -d mbedtls-2.16.3 < mbedtls-win32.patch
	$(MAKE) -j4 -C mbedtls-2.16.3/library CC=$(CC) CXX=$(CXX) CFLAGS="$(CFLAGS)" LDFLAGS=$(LIBS)
	mkdir -p lib; mkdir -p include
	cp mbedtls-2.16.3/library/*.a lib
	cp -r mbedtls-2.16.3/include/mbedtls include

curl:
	wget https://curl.haxx.se/download/curl-7.66.0.tar.xz
	tar xvf curl-7.66.0.tar.xz
	patch -p1 < curl-win32.patch
	cd curl-7.66.0; ./configure --host=i686-w64-mingw32 --target=i686-w64-mingw32 CC=$(CC) CXX=$(CXX) CFLAGS="$(CFLAGS)" LIBS=$(LIBS) --disable-shared --without-zlib --without-ssl --with-mbedtls=$(PWD) --enable-optimize --enable-http --disable-ftp --disable-file --disable-ldap  --disable-ldaps  --disable-rtsp --enable-proxy --disable-dict --disable-telnet --disable-tftp --disable-pop3 --disable-imap --disable-smb --disable-smtp --disable-gopher --enable-manual
	$(MAKE) -j4 -C curl-7.66.0

lokinet-bootstrap.exe: mbedtls curl dbghelp
	cp curl-7.66.0/src/curl.exe $@
	wget -O rootcerts.pem https://curl.haxx.se/ca/cacert.pem
	cp ../LICENSE .;unix2dos LICENSE LICENSE

dbghelp:
	wget https://snowlight.net/loki/win32-dist/dbghelp32.dll
	wget https://snowlight.net/loki/win32-dist/dbghelp64.dll

else
regdbhelper.dll:
	wget https://snowlight.net/loki/win32-dist/dbghelp32.dll
	wget https://snowlight.net/loki/win32-dist/dbghelp64.dll
	wget https://snowlight.net/loki/win32-dist/regdbhelper.dll

lokinet-bootstrap.exe:
	wget https://snowlight.net/loki/win32-dist/lokinet-bootstrap.exe
	wget -O rootcerts.pem https://curl.haxx.se/ca/cacert.pem
	cp ../LICENSE .;unix2dos LICENSE LICENSE

dbghelp:
	:
endif

# Common rules
7z.exe:
	wget https://snowlight.net/loki/win32-dist/7z.exe

tcpv6:
	wget https://snowlight.net/loki/win32-dist/inet6.7z

tap-win32:
	wget https://snowlight.net/loki/win32-dist/tap-windows-9.21.2.7z
	mv tap-windows-9.21.2.7z tuntapv9_n6.7z
	wget https://snowlight.net/loki/win32-dist/tap-windows-9.9.2_3.7z
	mv tap-windows-9.9.2_3.7z tuntapv9.7z

clean:
	-rm -rf curl-7* include lib mbedtls-2* *.exe *.dll *.pem *.7z