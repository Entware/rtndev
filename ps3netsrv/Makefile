# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2025 Entware
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ps3netsrv
PKG_VERSION:=1.47.48
PKG_REV:=079000f2bcbb61a8c936161a78307a3ae1f0dfec
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/aldostools/webMAN-MOD.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=5ff00a2236c2ef90478fe8a785628d340f7d0db6eece89820116ca6922077d9b

include $(INCLUDE_DIR)/package.mk

MAKE_PATH:=_Projects_/$(PKG_NAME)
MAKE_FLAGS+=-f Makefile.linux

define Package/ps3netsrv/Default
	SECTION:=net
	CATEGORY:=Network
	DEPENDS:=+libstdcpp
	TITLE:=C++ implementation of the ps3netsrv server
	URL:=$(PKG_SOURCE_URL)
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/ps3netsrv
$(call Package/ps3netsrv/Default)
	VARIANT:=nossl
	TITLE+= (no SSL)
endef

define Package/ps3netsrv-mbedtls
$(call Package/ps3netsrv/Default)
	VARIANT:=mbedtls
	TITLE+= (Mbed TLS)
	DEPENDS+=+libmbedtls
endef

define Package/ps3netsrv/description/Default
 C++ implementation of the ps3netsrv server.
endef

ifeq ($(BUILD_VARIANT),nossl)
	TARGET_CFLAGS += -DNOSSL
endif

ifeq ($(BUILD_VARIANT),mbedtls)
	TARGET_LDFLAGS += -lmbedtls -lmbedcrypto
endif

define Package/ps3netsrv/install
	$(INSTALL_DIR) $(1)/opt/sbin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(MAKE_PATH)/ps3netsrv $(1)/opt/sbin
	$(INSTALL_DIR) $(1)/opt/etc/init.d
	$(INSTALL_BIN) ./files/S76ps3netsrv $(1)/opt/etc/init.d
	$(INSTALL_DIR) $(1)/opt/share/ps3netsrv/{GAMES,PS3ISO}
endef

Package/ps3netsrv-mbedtls/install=$(Package/ps3netsrv/install)

$(eval $(call BuildPackage,ps3netsrv))
$(eval $(call BuildPackage,ps3netsrv-mbedtls))
