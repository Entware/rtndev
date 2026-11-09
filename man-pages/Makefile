#
# Copyright (C) 2017-2026 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=man-pages
PKG_VERSION:=6.20
PKG_RELEASE:=2

PKG_SOURCE_URL:=https://www.kernel.org/pub/linux/docs/man-pages
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=46f325713f2fd75c8d1f4fa42748153526a44846806d37028fab85cd0143de46

include $(INCLUDE_DIR)/package.mk

define Package/man-pages
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=unix manual pages
	DEPENDS:=+man-db
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/man-pages/description
 Linux kernel and C library user-space interface documentation.
endef

define Build/Compile
endef

define Package/man-pages/install
	$(INSTALL_DIR) $(1)/opt/share/man
	$(CP) $(PKG_BUILD_DIR)/man/man[1-8]* $(1)/opt/share/man
	$(RM) $(1)/opt/share/man/man7/man.7
endef

define Package/man-pages/postinst
#!/bin/sh
echo 'Creating man database...'
mandb -c
endef

$(eval $(call BuildPackage,man-pages))
