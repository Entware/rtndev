#
# Copyright (C) 2022-2025 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=7-zip
PKG_VERSION:=25.01
PKG_RELEASE:=1

PKG_SOURCE:=7z2501-src.tar.xz
PKG_SOURCE_URL:=https://www.7-zip.org/a
PKG_HASH:=ed087f83ee789c1ea5f39c464c55a5c9d4008deb0efe900814f2df262b82c36e

include $(INCLUDE_DIR)/package.mk

PKG_UNPACK:=$(HOST_TAR) -C $(PKG_BUILD_DIR) -xf $(DL_DIR)/$(PKG_SOURCE)

define Package/7-zip
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Compression
	DEPENDS:=+libpthread +libstdcpp
	TITLE:=file archiver with a high compression ratio
	URL:=https://www.7-zip.org
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/7-zip/description
 File archiver with a high compression ratio.
endef

MAKE_PATH:=CPP/7zip/Bundles/Alone2

MAKE_VARS += \
	MY_ARCH="$(TARGET_CFLAGS) $(TARGET_LDFLAGS)"

define Build/Prepare
	$(PKG_UNPACK)
	chmod +w -R $(PKG_BUILD_DIR)/*
	$(Build/Patch)
endef

define Build/Compile
	$(call Build/Compile/Default,-f makefile.gcc)
endef

define Package/7-zip/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(MAKE_PATH)/_o/7zz $(1)/opt/bin
endef

$(eval $(call BuildPackage,7-zip))
