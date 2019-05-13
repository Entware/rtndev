#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ncdc
PKG_VERSION:=1.22
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://dev.yorhel.nl/download
PKG_HASH:=fd41ef85cec3eca0107d83583ad25faa8804dd22d76f6da7fc157e0233b13a59

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/ncdc
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=P2P
	TITLE:=ncdc is a modern and lightweight DC client
	DEPENDS:=+libncursesw +bzip2 +libgnutls +libsqlite3 +glib2 $(ICONV_DEPENDS)
	URL:=http://dev.yorhel.nl/ncdc
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ncdc/description
 ncdc is a modern and lightweight direct connect client with a friendly
 ncurses interface.
endef

define Build/Compile
	$(HOSTCC) $(PKG_BUILD_DIR)/deps/makeheaders.c -o $(PKG_BUILD_DIR)/makeheaders
	$(call Build/Compile/Default)
endef

define Package/ncdc/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ncdc $(1)/opt/bin
endef

$(eval $(call BuildPackage,ncdc))
