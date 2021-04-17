#
# Copyright (C) 2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=libcryptopp
PKG_VERSION:=5.6.4
PKG_REV:=4132d85888ac6c30729f58bb442a4a26a5b16cfe
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/weidai11/cryptopp.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=70f092de10ae3a5dfecbfb8eaabc6cf6df6530e844fda80b5fd431baedd6150e

PKG_BUILD_PARALLEL:=1
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/libcryptopp
	SECTION:=libs
	CATEGORY:=Libraries
	DEPENDS:=+libstdcpp
	TITLE:=C++ class library of cryptographic schemes
	MENU:=1
	URL:=https://www.cryptopp.com/
endef

define Package/libcryptopp/description
 Crypto++ Library is a free C++ class library of cryptographic schemes.
endef

define Package/libcryptopp/config
	if PACKAGE_libcryptopp
		config LIBCRYPTOPP_TESTSUITE
			bool "Add native test suite"
			default n
	endif
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(RM) $(PKG_BUILD_DIR)/GNUmakefile
endef

TARGET_CFLAGS += $(FPIC)

CMAKE_OPTIONS += \
	-DDISABLE_ASM=ON \
	-DDISABLE_SSSE3=ON \
	-DDISABLE_AESNI=ON \
	-DBUILD_TESTING=$(if $(CONFIG_LIBCRYPTOPP_TESTSUITE),ON,OFF)

define Build/InstallDev
	$(INSTALL_DIR) $(1)/opt/include
	$(CP) $(PKG_INSTALL_DIR)/opt/include/cryptopp $(1)/opt/include
	$(INSTALL_DIR) $(1)/opt/lib
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/lib/libcryptopp.{a,so*} $(1)/opt/lib
endef

define Package/libcryptopp/install
	$(INSTALL_DIR) $(1)/opt/lib
	$(CP) $(PKG_INSTALL_DIR)/opt/lib/libcryptopp.so* $(1)/opt/lib
ifeq ($(CONFIG_LIBCRYPTOPP_TESTSUITE),y)
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cryptest.exe $(1)/opt/bin
	$(INSTALL_BIN) files/cryptest.sh $(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/share
	$(CP) $(PKG_INSTALL_DIR)/opt/share/cryptopp $(1)/opt/share
endif
endef

$(eval $(call BuildPackage,libcryptopp))
