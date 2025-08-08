# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2025 Entware

# https://github.com/Entware/Entware/issues/1010

include $(TOPDIR)/rules.mk

PKG_NAME:=tsping
PKG_VERSION:=0.2.3
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/Lochnair/tsping/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=d02874237cc25367dcb828e3b92f20114f939e292eb26730af6d1d69bba04368

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=BSD-3-Clause
PKG_LICENSE_FILES:=LICENSE.md

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/meson.mk

define Package/tsping
  SECTION:=net
  CATEGORY:=Network
  TITLE:=Utility for sending timestamp pings
  URL:=https://github.com/Lochnair/tsping
endef

define Package/tsping/description
  tsping - a simple application to send ICMP echo/timestamp requests.
endef

define Package/tsping/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(MESON_BUILD_DIR)/tsping $(1)/opt/sbin
endef

$(eval $(call BuildPackage,tsping))
