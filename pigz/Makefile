#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pigz
PKG_VERSION:=2.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=http://zlib.net/pigz
PKG_HASH:=a4f816222a7b4269bd232680590b579ccc72591f1bb5adafcd7208ca77e14f73

include $(INCLUDE_DIR)/package.mk

define Package/pigz
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Compression
	TITLE:=pigz is a parallel implementation of gzip
	DEPENDS:=+zlib +USE_UCLIBC:librt
	URL:=http://zlib.net/pigz/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pigz/description
 pigz stands for parallel implementation of gzip, is a fully functional replacement for gzip
 that exploits multiple processors and multiple cores to the hilt when compressing data.
endef

define Package/pigz/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/{pigz,unpigz} $(1)/opt/bin
endef

$(eval $(call BuildPackage,pigz))
