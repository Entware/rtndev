# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=cryfs
PKG_VERSION:=1.0.1
PKG_RELEASE:=1

PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cryfs/cryfs
PKG_MIRROR_HASH:=114e999ab5b40faa200a88d199c5dd0b209f91ed2077b8003b4d8c5eb01180d4

PKG_MAINTAINER:=Entware team, https://entware.net
PKG_LICENSE:=LGPL-3.0-only
PKG_LICENSE_FILES:=LICENSE.txt

PKG_BUILD_DEPENDS:=range-v3 spdlog

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/cryfs
  SECTION:=utils
  CATEGORY:=Utilities
  SUBMENU:=Filesystem
  TITLE:=Cryptographic filesystem for the cloud
  URL:=https://www.cryfs.org
  DEPENDS:=+boost-atomic +boost-chrono +boost-container +boost-date_time
  DEPENDS+=+boost-filesystem +boost-program_options +boost-thread
  DEPENDS+=+fuse-utils +libfmt +libstdcpp
endef

define Package/cryfs/description
 CryFS encrypts your files, so you can safely store them anywhere.
 It works well together with cloud services like Dropbox, iCloud, OneDrive and
 others.
endef

CMAKE_OPTIONS += \
	-DCRYFS_UPDATE_CHECKS=OFF \
	-DDISABLE_OPENMP=ON

TARGET_CPPFLAGS += -DCRYPTOPP_DISABLE_ASM

define Package/cryfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/cryfs{,-unmount} $(1)/opt/bin
endef

$(eval $(call BuildPackage,cryfs))
