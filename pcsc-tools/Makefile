#
# Copyright (C) 2011-2016 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pcsc-tools
PKG_VERSION:=1.4.27-20161126
PKG_REV:=33dea586fc8ab951edb78d5a3ac9a2dabf2d8baf
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/LudovicRousseau/pcsc-tools.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/pcsc-tools
	SECTION:=utils
	CATEGORY:=Utilities
	DEPENDS:=+libpcsclite
	TITLE:=usefull tools for a PC/SC user
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/pcsc-tools/description
 Some tools to be used with smart cards and PC/SC.
endef

define Package/pcsc-tools/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pcsc_scan $(1)/opt/bin
endef

$(eval $(call BuildPackage,pcsc-tools))
