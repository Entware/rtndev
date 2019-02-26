#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=duktape
PKG_VERSION:=2.3.0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.xz
PKG_SOURCE_URL:=http://duktape.org
PKG_HASH:=ed6e2f3ab2061628a7aeee27ccff16538ba6a151480cccf2e846bd061e45afe8

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/duktape
	SECTION:=lang
	CATEGORY:=Languages
	SUBMENU:=JavaScript
	DEPENDS:=+libreadline +libncurses
	TITLE:=Duktape JavaScript engine
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/duktape/description
 Duktape is an embeddable Javascript engine, with a focus on portability and
 compact footprint.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(PKG_BUILD_DIR)/Makefile.sharedlibrary $(PKG_BUILD_DIR)/Makefile
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/*.h $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libduktape.so* $(1)/opt/lib
endef

define Package/duktape/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libduktape.so* $(1)/opt/lib
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/duk $(1)/opt/bin
	$(LN) duk $(1)/opt/bin/js
endef

$(eval $(call BuildPackage,duktape))
