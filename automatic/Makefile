#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=automatic
PKG_VERSION:=0.8.3-20200405
PKG_REV:=cc988b8459c38c939c5d85868a92cd808c815bb4
PKG_RELEASE:=2

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/1100101/Automatic.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f6cde8c5343c605981a221c039c04bfe796397b4c2e3810f45fcb6e9880a4570

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/automatic
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=BitTorrent
	DEPENDS:=+libcurl +libpcre +libxml2
	TITLE:=RSS torrents downloader
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/automatic/description
 Automatic is a RSS daemon that downloads torrent files matching regular
 expression patterns at certain intervals.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(SED) 's|`git rev-parse --short HEAD`|$(PKG_REV)|g' \
	    $(PKG_BUILD_DIR)/src/Makefile.am
endef

define Package/automatic/conffiles
/opt/etc/automatic.conf
endef

define Package/automatic/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/automatic $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/etc/automatic.conf-sample $(1)/opt/etc/automatic.conf
	$(INSTALL_BIN) ./files/S91automatic $(1)/opt/etc/init.d
endef

$(eval $(call BuildPackage,automatic))
