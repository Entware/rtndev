#
# Copyright (C) 2009 Brice DUBOST
# Copyright (C) 2011-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2009

include $(TOPDIR)/rules.mk

PKG_NAME:=transcode
PKG_VERSION:=1.1.7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://distfiles.macports.org/transcode
PKG_HASH:=1e4e72d8e0dd62a80b8dd90699f5ca64c9b0cb37a5c9325c184166a9654f0a92

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/transcode
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+zlib +libpthread
	TITLE:=A/V transcoding suite
	URL:=https://sourceforge.net/projects/tcforge.berlios/
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
	$(SED) 's,^#!.*gawk,#!/opt/bin/gawk,' $(1)/opt/lib/transcode/{filter_list,parse_csv}.awk
endef

$(eval $(call BuildPackage,transcode))
