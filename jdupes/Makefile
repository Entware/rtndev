#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=jdupes
PKG_VERSION:=1.12
PKG_REV:=5f8b05ba91741ab00f62b10d767175122c5d19ab
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/jbruchon/jdupes.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/jdupes
  SECTION:=utils
  CATEGORY:=Utilities
  TITLE:=jdupes
  URL:=https://github.com/jbruchon/jdupes
  MAINTAINER:=Entware team, https://entware.net
endef

define Package/jdupes/description
 jdupes is a program for identifying or deleting duplicate files residing
 within specified directories.
endef

define Package/jdupes/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/jdupes $(1)/opt/bin
endef

$(eval $(call BuildPackage,jdupes))
