# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=iprange
PKG_VERSION:=1.0.4
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_URL:=https://github.com/firehol/iprange/releases/download/v$(PKG_VERSION)
PKG_HASH:=296ff1813ff4b3448c686c03cf3af8826e328baaa19dc8e40778dccf27c71b16

include $(INCLUDE_DIR)/package.mk

define Package/iprange
	SECTION:=net
	CATEGORY:=Network
	TITLE:=manage IP ranges
	URL:=https://github.com/firehol/iprange
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/iprange/description
 Manage IP ranges.
endef

define Package/iprange/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/iprange $(1)/opt/bin
endef

$(eval $(call BuildPackage,iprange))
