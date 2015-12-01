#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# vovic67 @ forum.zyxmon.org, mediatomb for Keenetic
# Abandoned in 2010

include $(TOPDIR)/rules.mk
include $(INCLUDE_DIR)/nls.mk

PKG_NAME:=mediatomb
PKG_VERSION:=0.12.1
PKG_RELEASE:=6

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/mediatomb
PKG_MD5SUM:=e927dd5dc52d3cfcebd8ca1af6f0d3c2

PKG_BUILD_PARALLEL:=0

include $(INCLUDE_DIR)/package.mk

define Package/mediatomb
	SECTION:=multimedia
	CATEGORY:=Multimedia
	DEPENDS:=+libexif +libsqlite3 +id3lib +file +libpthread +libmagic \
		+libjs +libexpat +libffmpeg +libstdcpp +libcurl +libopenssl \
		+$(ICONV_DEPENDS)
	TITLE:=A powerfull UPNP media server
	URL:=http://www.mediatomb.cc
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/mediatomb/description
 MediaTomb is an open source (GPL) UPnP MediaServer with a web UI and
 with the aim of being fully compliant with DLNA/UPnP-AV clients.
endef

define Package/mediatomb/conffiles
/opt/etc/mediatomb/config.xml
/opt/etc/mediatomb/mediatomb.db
endef

CONFIGURE_ARGS += \
	--prefix=/opt \
	--enable-pthread-lib \
	--enable-inotify \
	--enable-db-autocreate \
	--enable-id3lib \
	--disable-taglib \
	--enable-libexif \
	--enable-libmagic \
	--enable-protocolinfo-extension \
	--disable-libextractor \
	--enable-ffmpeg \
	--enable-libjs \
	--disable-tombdebug \
	--disable-upnpdebug \
	--disable-youtube \
	--disable-curl \
	--enable-sqlite3 \
	--enable-sqlite-backup-defaults \
	--disable-mysql \
	--disable-external-transcoding \
	--disable-ffmpegthumbnailer \
	--disable-libmp4v2 \
	--disable-lastfmlib \
	--enable-libexif \
	--enable-iconv-lib \
	--with-iconv-h=$(ICONV_PREFIX)/include \
	--with-iconv-libs=$(ICONV_PREFIX)/lib \
	--with-js-h=$(STAGING_DIR)/opt/include/js \
	--disable-libmp4v2

define Build/Compile
	$(MAKE) -C $(PKG_BUILD_DIR) \
		HOSTCC="$(HOSTCC)" \
		DESTDIR="$(PKG_INSTALL_DIR)" \
		all install
endef

define Package/mediatomb/install
	$(INSTALL_DIR) $(1)/opt/etc/mediatomb $(1)/opt/bin $(1)/opt/share $(1)/opt/var/mediatomb
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/mediatomb $(1)/opt/bin/
	$(CP)  $(PKG_INSTALL_DIR)/opt/share/* $(1)/opt/share/
	$(INSTALL_DATA) ./files/config.xml $(1)/opt/etc/mediatomb/
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S90mediatomb $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,mediatomb))
