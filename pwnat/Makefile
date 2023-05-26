#
# Copyright (C) 2011-2023 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=pwnat
PKG_VERSION:=0.3.1-beta
PKG_REV:=c2d3bf4b41fed65ea930ecb345eabe8453310eea
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/samyk/pwnat.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f0c715db89705e8cfb63fee317af9b18f16e02faa0fc5a58b6928e726438454d

include $(INCLUDE_DIR)/package.mk

define Package/pwnat
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Firewall
	TITLE:=NAT traversal tool
	URL:=https://samy.pl/pwnat/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/pwnat/description
 The only tool to punch holes through firewalls/NATs where both
 clients and server can be behind separate NATs without any 3rd party
 involvement.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	mkdir $(PKG_BUILD_DIR)/obj
endef

define Package/pwnat/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/pwnat $(1)/opt/sbin
endef

$(eval $(call BuildPackage,pwnat))
