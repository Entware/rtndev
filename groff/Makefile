#
# Copyright (C) 2017-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=groff
PKG_VERSION:=1.23.0
PKG_RELEASE:=1

PKG_SOURCE_URL:=@GNU/groff
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_HASH:=6b9757f592b7518b4902eb6af7e54570bdccba37a871fddb2d30ae3863511c13

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/groff
	SECTION:=utils
	CATEGORY:=Utilities
	TITLE:=GNU troff text-formatting system
	URL:=https://www.gnu.org/software/groff/
	DEPENDS:=+libstdcpp $(ICONV_DEPENDS) $(INTL_DEPENDS)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/groff/description
 This package contains optional components of the GNU troff
 text-formatting system.
endef

define Package/groff/install
	$(INSTALL_DIR) $(1)/opt/{bin,share/groff}
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/{g,n,t}roff $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grotty $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/tbl $(1)/opt/bin
	$(CP) $(PKG_INSTALL_DIR)/opt/share/groff $(1)/opt/share
	$(FIND) $(1)/opt/share -type f | $(XARGS) $(SED) 's,/usr/share,/opt/share,g'
endef

$(eval $(call BuildPackage,groff))
