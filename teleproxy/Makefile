# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=teleproxy
PKG_VERSION:=4.16.1
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://codeload.github.com/teleproxy/teleproxy/tar.gz/refs/tags/v$(PKG_VERSION)?
PKG_HASH:=08d9c73810d660826150f9796ac76e175ecc7648369a8a59986bddd1c1ee9226

PKG_LICENSE:=GPL-2.0-or-later AND LGPL-2.0-or-later
PKG_LICENSE_FILES:=GPLv2 LGPLv2

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/teleproxy
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Web Servers/Proxies
	TITLE:=Telegram proxy service
	URL:=https://github.com/teleproxy/teleproxy
	DEPENDS:=+zlib +libopenssl +libpthread +libatomic +librt
endef

define Package/teleproxy/description
 High-performance MTProto proxy for Telegram with DPI resistance and fake-TLS
 camouflage.
endef

MAKE_FLAGS += \
	HOST_ARCH="$(ARCH)" \
	EXTRA_VERSION="$(PKG_VERSION)" \
	COMMIT=01a3e01f5f1aa0bacb20b4f8c7f10449ed12a1da \
	EXTRA_CFLAGS="$(TARGET_CPPFLAGS) $(TARGET_CFLAGS)" \
	EXTRA_LDFLAGS="$(TARGET_LDFLAGS)" \
	LIBUNWIND_CFLAGS= LIBUNWIND_LDFLAGS=

define Package/teleproxy/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/objs/bin/teleproxy $(1)/opt/bin/
endef

$(eval $(call BuildPackage,teleproxy))
