#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ps3netsrv
PKG_VERSION:=1.47.35
PKG_REV:=1b8d5990e2072548d06072074c6039c18a3760b0
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/aldostools/webMAN-MOD.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=f709b3f1640440b620edb5396c9b1b047bd9951623e48c6258d4ead4281d9760

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
