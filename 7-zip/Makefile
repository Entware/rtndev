#
# Copyright (C) 2022 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=7-zip
PKG_VERSION:=24.07
PKG_RELEASE:=1

PKG_SOURCE:=7z2407-src.tar.xz
PKG_SOURCE_URL:=https://www.7-zip.org/a
PKG_HASH:=d1b0874a3f1c26df21c761a4a30691dc1213e8577f18ee78326c14ca4d683e2b

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
