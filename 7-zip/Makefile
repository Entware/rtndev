#
# Copyright (C) 2022 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=7-zip
PKG_VERSION:=22.01
PKG_RELEASE:=1

PKG_SOURCE:=7z2201-src.tar.xz
PKG_SOURCE_URL:=https://www.7-zip.org/a
PKG_HASH:=393098730c70042392af808917e765945dc2437dee7aae3cfcc4966eb920fbc5

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

define Build/Compile
	$(call Build/Compile/Default,-f makefile.gcc)
endef

define Package/7-zip/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/$(MAKE_PATH)/_o/7zz $(1)/opt/bin
endef

$(eval $(call BuildPackage,7-zip))
