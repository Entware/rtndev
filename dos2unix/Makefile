#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dos2unix
PKG_VERSION:=7.4.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=1cd58a60b03ed28fa39046102a185c5e88c4f7665e1e0417c25de7f8b9f78623

include $(INCLUDE_DIR)/package.mk

define Package/dos2unix
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=text file format converter
	URL:=http://waterlan.home.xs4all.nl/dos2unix.html
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/dos2unix/description
 DOS/Mac to Unix and vice versa text file format converter.
endef

define Package/dos2unix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{unix2dos,dos2unix} $(1)/opt/bin
endef

$(eval $(call BuildPackage,dos2unix))
