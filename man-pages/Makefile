#
# Copyright (C) 2017
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=man-pages
PKG_VERSION:=4.14
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://www.kernel.org/pub/linux/docs/man-pages/
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=aeebc6b09a11e7f7bbc98f3984fe8b8b2bde9d2f5f9dcbd4348a9e0d93704238

#PKG_LICENSE:=

include $(INCLUDE_DIR)/package.mk

define Package/man-pages
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=unix manual pages
  DEPENDS:=+man-db
  MAINTAINER:=Entware team, http://entware.net
endef

define Package/man-pages/description
  Linux kernel and C library user-space interface documentation.
endef

define Package/man-pages/install
	$(INSTALL_DIR) $(1)/opt/share/man
	$(CP) $(PKG_BUILD_DIR)/man[1-8] $(1)/opt/share/man/
endef

define Package/man-pages/postinst
#!/bin/sh
echo "Now we need to create a database..."
mandb -c
endef

$(eval $(call BuildPackage,man-pages))
