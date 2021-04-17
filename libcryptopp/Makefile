#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libcryptopp
PKG_VERSION:=8.5.0
PKG_REV:=f2102243e6fdd48c0b2a393a0993cca228f20573
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/weidai11/cryptopp.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=a0cbc9c88314c654567af0c25bfd5c230217c11896adc7c5d167c8835827424a

PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk

define Package/libcryptopp
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp +libpthread
	TITLE:=C++ class library of cryptographic schemes
	URL:=https://www.cryptopp.com/
endef

define Package/libcryptopp/description
 Crypto++ Library is a free C++ class library of cryptographic schemes.
endef

TARGET_CFLAGS += $(FPIC)

MAKE_VARS += \
	LINK_LIBRARY=libcryptopp.so \
	PREFIX=/opt

define Build/Prepare
	$(call Build/Prepare/Default)
	cp -f $(PKG_BUILD_DIR)/GNUmakefile-cross $(PKG_BUILD_DIR)/GNUmakefile
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/cryptopp $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libcryptopp.so $(1)/opt/lib
endef

define Package/libcryptopp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libcryptopp.so $(1)/opt/lib

# Uncomment this section to run tests on target platform
#	$(INSTALL_DIR) $(1)/opt/bin
#	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cryptest.exe $(1)/opt/bin
#	$(INSTALL_BIN) files/cryptest.sh $(1)/opt/bin
#	$(INSTALL_DIR) $(1)/opt/share
#	$(CP) $(PKG_INSTALL_DIR)/opt/share/cryptopp $(1)/opt/share
endef

$(eval $(call BuildPackage,libcryptopp))
