#
# Copyright (C) 2009 Brice DUBOST
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=transcode
PKG_VERSION:=1.1.5
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=@SF/tcforge.berlios
PKG_HASH:=7e01665079eef81625c4761cc5c08a3b53b97de90fb0728d64f5a86a3bc59009

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/transcode
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+zlib +libpthread
	TITLE:=A/V transcoding suite
	URL:=http://tcforge.berlios.de/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/transcode/description
 Transcode is a suite of tools, all of which are command line utilities
 for transcoding various video, audio, and container formats. Please note
 it's compiled without any external recoding libraries because transcoding is
 too heavy task for a router. Only few tools will be usefull, i.e. tcprobe.
endef

CONFIGURE_ARGS += \
	--disable-mmx \
	--disable-3dnow \
	--disable-sse \
	--disable-sse2 \
	--disable-altivec \
	--disable-ffmpeg \
	--disable-libavcodec \
	--disable-libavformat \
	--disable-x86-textrels \
	--disable-libdvdread \
	--disable-lame \
	--disable-iconv \
	--disable-libjpeg \
	--without-x

define Package/transcode/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/* $(1)/opt/bin/
	$(INSTALL_DIR) $(1)/opt/lib/transcode
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/transcode/{*.so,xvid4.cfg,filter_list.awk,parse_csv.awk} \
			$(1)/opt/lib/transcode
endef

$(eval $(call BuildPackage,transcode))
