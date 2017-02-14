#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2007

include $(TOPDIR)/rules.mk

PKG_NAME:=wdfs
PKG_VERSION:=1.4.2
PKG_RELEASE:=3

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://noedler.de/projekte/wdfs/
PKG_MD5SUM:=628bb44194d04c1cf8aacc446ed0a230

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/wdfs
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libneon +libfuse +libopenssl +glib2 $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=webdav filesystem for fuse
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/wdfs/description
 wdfs is a webdav filesystem that makes it possible to mount a webdav share
 under linux, freebsd and apple mac os x. wdfs has some special features
 for accessing subversion repositories via webdav.
endef

TARGET_LDFLAGS += \
	-lpthread

define Package/wdfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/wdfs $(1)/opt/bin
endef

$(eval $(call BuildPackage,wdfs))
