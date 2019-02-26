#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=man-pages
PKG_VERSION:=4.16
PKG_RELEASE:=1

PKG_SOURCE_URL:=https://www.kernel.org/pub/linux/docs/man-pages/
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=d38b0460bf3f35c95faf7f8cf52dac1216d86a47866f5e5f2fda88c61da04960

#PKG_LICENSE:=

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
