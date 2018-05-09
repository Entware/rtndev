#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=baidupcs
PKG_VERSION:=0.3.1
PKG_REV:=92c6141e4dd55b312ebda9f1849237f1963e2644
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/GangZhuo/BaiduPCS.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/baidupcs
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libcurl +libpthread
	TITLE:=Baidu cloud client
	URL:=https://github.com/GangZhuo/BaiduPCS
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/baidupcs/description
 The terminal utility for Baidu Network Disk.
endef

CONFIGURE_ARGS += \
	--with-openssl="$(STAGING_DIR)/opt" \
	--with-crypto

define Package/baidupcs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/baidupcs $(1)/opt/bin
endef

$(eval $(call BuildPackage,baidupcs))
