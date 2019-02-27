#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# Abandoned in 2012

include $(TOPDIR)/rules.mk

PKG_NAME:=yamdi
PKG_VERSION:=1.9
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=@SF/$(PKG_NAME)
PKG_HASH:=4a6630f27f6c22bcd95982bf3357747d19f40bd98297a569e9c77468b756f715

include $(INCLUDE_DIR)/package.mk

define Package/yamdi
	SECTION:=multimedia
	CATEGORY:=Multimedia
	TITLE:=FLV metadata injector
	URL:=http://yamdi.sourceforge.net/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/yamdi/description
 yamdi stands for Yet Another MetaData Injector and is a metadata injector
 for FLV files. It adds the onMetaData event to your FLV files.
endef

define Package/yamdi/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/yamdi $(1)/opt/bin/
endef

$(eval $(call BuildPackage,yamdi))
