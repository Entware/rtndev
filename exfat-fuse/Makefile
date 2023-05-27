#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=exfat-fuse
PKG_VERSION:=1.4.0
PKG_REV:=0372fdeab2b878736fa20c9c510a0766a7996cdc
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/relan/exfat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=7e678c2d9b7bdb2e2449a750aaa3ab97eb86466358bf5b87e8c4a1fde81fa9ec

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/exfat-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +fuse3-utils +libpthread
	TITLE:=a full-featured exFAT file system implementation
	URL:=https://github.com/relan/exfat
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/exfat-fuse/description
 This project aims to provide a full-featured exFAT file system implementation
 for Unix-like systems. It consists of a FUSE module (fuse-exfat) and a set of
 utilities (exfat-utils).
endef



define Package/exfat-fuse/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(CP) $(PKG_INSTALL_DIR)/opt/sbin/* $(1)/opt/sbin
endef

$(eval $(call BuildPackage,exfat-fuse))
