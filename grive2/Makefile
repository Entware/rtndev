# SPDX-License-Identifier: GPL-2.0-only
#
# Copyright (C) 2011-2026 Entware

include $(TOPDIR)/rules.mk

PKG_NAME:=grive2
PKG_VERSION:=0.5.3
PKG_REV:=d03c4a24ceb179d0fdb4c47e3d144d547ffcc8b6
# boost bumped
PKG_RELEASE:=6

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vitalif/grive2.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=89decea20cc1f63c46365b80c1f84a785e429d8129e5fbfb41d97ad9754e8437

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/grive2
  SECTION:=net
  CATEGORY:=Network
  SUBMENU:=Filesystem
  TITLE:=a fork of original Google Drive client
  URL:=https://github.com/vitalif/grive2
  DEPENDS:=+boost-atomic +boost-filesystem +boost-program_options +boost-regex
  DEPENDS+=+libbfd +libcurl +libgcrypt +libgpg-error +libstdcpp +yajl $(INTL_DEPENDS)
endef

define Package/grive2/description
 This is the fork of original "Grive" (https://github.com/Grive/grive) Google
 Drive client with the support for the new Drive REST API and partial sync.
endef

TARGET_CXXFLAGS += -fpermissive -DBOOST_BIND_GLOBAL_PLACEHOLDERS
TARGET_LDFLAGS += $(if $(INTL_FULL),-lintl)

ifneq ($(CONFIG_USE_GLIBC),y)
define Build/Prepare
	$(Build/Prepare/Default)
	$(SED) 's,find_package(BFD),#find_package(BFD),g' $(PKG_BUILD_DIR)/libgrive/CMakeLists.txt
endef
endif

define Package/grive2/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grive $(1)/opt/bin
endef

$(eval $(call BuildPackage,grive2))
