#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# vovic67 @ forum.zyxmon.org, mediatomb for Keenetic
# Abandoned in 2010

include $(TOPDIR)/rules.mk

PKG_NAME:=mediatomb
PKG_VERSION:=0.12.1-20140713
PKG_RELEASE:=2
PKG_FIXUP:=autoreconf

PKG_REV:=7ab761696354868bd5d67ff4f2d849994e4c98e2
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=git://git.code.sf.net/p/mediatomb/code
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_BUILD_PARALLEL:=0
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/mediatomb
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libexif +libsqlite3 +id3lib +file +libjs +libexpat \
		+$(ICONV_DEPENDS) +libuuid +libflac +libffmpegthumbnailer
	TITLE:=A powerfull UPNP media server
	URL:=http://www.mediatomb.cc
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/mediatomb/description
 MediaTomb is an open source (GPL) UPnP MediaServer with a web UI and
 with the aim of being fully compliant with DLNA/UPnP-AV clients.
endef

define Package/mediatomb/conffiles
/opt/etc/mediatomb/config.xml
endef

TARGET_LDFLAGS += -lm -ldl -ljs
TARGET_CXXFLAGS += -I$(STAGING_DIR)/opt/include/js

CONFIGURE_ARGS += \
	--enable-pthread-lib \
	--enable-inotify \
	--enable-db-autocreate \
	--enable-id3lib \
	--disable-taglib \
	--enable-libexif \
	--enable-libmagic \
	--enable-protocolinfo-extension \
	--enable-ffmpeg \
	--enable-libjs \
	--disable-tombdebug \
	--disable-upnpdebug \
	--disable-youtube \
	--disable-curl \
	--enable-sqlite3 \
	--enable-sqlite-backup-defaults \
	--disable-mysql \
	--enable-external-transcoding \
	--enable-ffmpegthumbnailer \
	--disable-libmp4v2 \
	--disable-lastfm \
	--enable-libexif \
	--enable-iconv-lib \
	--with-iconv-h=$(ICONV_PREFIX)/include \
	--with-iconv-libs=$(ICONV_PREFIX)/lib \
	--disable-libmp4v2

define Package/mediatomb/install
	$(INSTALL_DIR) $(1)/opt/etc/mediatomb $(1)/opt/bin $(1)/opt/share $(1)/opt/var
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mediatomb $(1)/opt/bin/
	$(CP) $(PKG_INSTALL_DIR)/opt/share/* $(1)/opt/share/
	$(INSTALL_DATA) ./files/config.xml $(1)/opt/etc/mediatomb/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S90mediatomb $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,mediatomb))
