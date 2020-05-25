#Original script obtained from:
#	https://gist.github.com/rafaelbiriba/7f2d7c6f6c3d6ae2a5cbCriando
#To that script, I have added the installation of libx264
#Once the file installs libraries and ffmpeg, I run the following command to crop video:
#	ffmpeg -i input.MP4 -ss 00:06:49 -to 00:09:49 -c:v libx264 -b:v 24500K -maxrate
#	26000K -bufsize 12000K -c:a aac -b:a 256K output.MP4

apt-get update
apt-get -y install autoconf automake build-essential git-core libass-dev libgpac-dev libsdl1.2-dev libtheora-dev libtool libvdpau-dev libvorbis-dev libx11-dev libxext-dev libxfixes-dev pkg-config texi2html zlib1g-dev libmp3lame-dev nasm gcc yasm && true
mkdir ~/ffmpeg_sources
cd ~/ffmpeg_sources
git clone --depth 1 git://github.com/mstorsjo/fdk-aac.git
cd fdk-aac
autoreconf -fiv
./configure --prefix="$HOME/ffmpeg_build" --disable-shared
make -j8
make install
make distclean
cd ~/ffmpeg_sources
wget https://sourceforge.net/projects/lame/files/lame/3.99/lame-3.99.5.tar.gz
tar xzvf lame-3.99.5.tar.gz
cd lame-3.99.5
./configure --prefix="$HOME/ffmpeg_build" --enable-nasm --disable-shared
make -j8
make install
make distclean
cd ~/ffmpeg_sources
git -C x264 pull 2> /dev/null || git clone --depth 1 https://code.videolan.org/videolan/x264.git
cd x264
./configure --prefix="$HOME/ffmpeg_build" --enable-static --enable-pic
make -j8
make install
make distclean
cd ~/ffmpeg_sources
wget https://ffmpeg.org/releases/ffmpeg-4.2.1.tar.gz
tar xzvf ffmpeg-4.2.1.tar.gz
cd ffmpeg-4.2.1
PKG_CONFIG_PATH="$HOME/ffmpeg_build/lib/pkgconfig"
export PKG_CONFIG_PATH
./configure --prefix="$HOME/ffmpeg_build" \
  --extra-cflags="-I$HOME/ffmpeg_build/include" --extra-ldflags="-L$HOME/ffmpeg_build/lib" \
  --bindir="$HOME/bin" --extra-libs="-ldl" --enable-gpl --enable-libass --enable-libfdk-aac \
  --enable-libmp3lame --enable-nonfree --enable-libx264
make -j8
make install
cp ffmpeg /usr/bin/
make distclean
hash -r
ffmpeg 2>&1 | head -n1
