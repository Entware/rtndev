#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=exfat-fuse
PKG_VERSION:=1.3.0
PKG_REV:=2ce337dc2628b1af270341a5a7a81e361f4e355f
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/relan/exfat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/exfat-fuse
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+fuse-utils +libpthread
	TITLE:=a full-featured exFAT file system implementation
	URL:=https://github.com/relan/exfat
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/exfat-fuse/description
 This project aims to provide a full-featured exFAT file system implementation for Unix-like systems.
 It consists of a FUSE module (fuse-exfat) and a set of utilities (exfat-utils).
endef



define Package/exfat-fuse/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(CP) $(PKG_INSTALL_DIR)/opt/sbin/* $(1)/opt/sbin
endef

$(eval $(call BuildPackage,exfat-fuse))
