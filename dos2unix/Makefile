#
# Copyright (C) 2011-2015 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=dos2unix
PKG_VERSION:=7.2.3
PKG_RELEASE:=1a

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_MD5SUM:=b4cd9540de21148555ee690cbb9b1bb7

include $(INCLUDE_DIR)/package.mk

define Package/dos2unix
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=text file format converter
	URL:=http://waterlan.home.xs4all.nl/dos2unix.html
	MAINTAINER:=Entware team, entware.wl500g.info
endef

define Package/dos2unix/description
 DOS/Mac to Unix and vice versa text file format converter
endef

define Package/dos2unix/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{unix2dos,dos2unix} $(1)/opt/bin
endef

$(eval $(call BuildPackage,dos2unix))
