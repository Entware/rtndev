#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=nonroot
PKG_VERSION:=20120608
PKG_RELEASE:=1

PKG_REV:=235dd1e519c95a9736a2dc0303c64fec358076e1
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/hampus/nonroot
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/nonroot
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=run commands as non-root
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/nonroot/description
 This is a small utility for starting executables as a non-privileged user,
 when running as the superuser (e.g. in an init-script).
endef

define Package/nonroot/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/usr/local/bin/nonroot $(1)/opt/bin/
endef

$(eval $(call BuildPackage,nonroot))
