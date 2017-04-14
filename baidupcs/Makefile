#
# Copyright (C) 2011-2017 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=baidupcs
PKG_VERSION:=0.2.5-20170306
PKG_REV:=13f244d7430036aa7864a1ad5e8c2d2ba62d23ba
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/GangZhuo/BaiduPCS.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk

define Package/baidupcs
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libcurl +libpthread
	TITLE:=Baidu cloud client
	URL:=https://github.com/GangZhuo/BaiduPCS
	MAINTAINER:=Entware team, http://entware.net
endef

define Package/baidupcs/description
 The terminal utility for Baidu Network Disk.
endef

define Package/baidupcs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/bin/pcs $(1)/opt/bin
endef

$(eval $(call BuildPackage,baidupcs))
