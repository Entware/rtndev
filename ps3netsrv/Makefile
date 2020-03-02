#
# Copyright (C) 2011-2020 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ps3netsrv
PKG_VERSION:=20190924
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)_$(PKG_VERSION).zip
PKG_SOURCE_URL:=https://github.com/aldostools/webMAN-MOD/releases/download/1.47.25
PKG_HASH:=d4f661a105ee7375271a2d33b9adb11dd51fa0ad1b239925ebaa58f5c107ffa7

PKG_BUILD_DIR:=$(BUILD_DIR)/$(PKG_NAME)-$(PKG_VERSION)-$(BUILD_VARIANT)
PKG_UNPACK:=unzip $(DL_DIR)/$(PKG_SOURCE) -d $(PKG_BUILD_DIR)

include $(INCLUDE_DIR)/package.mk

MAKE_PATH:=$(PKG_NAME)
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
