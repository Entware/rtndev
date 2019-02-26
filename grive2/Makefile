#
# Copyright (C) 2011-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=grive2
PKG_VERSION:=0.5.1-20180819
PKG_REV:=cf51167b55246b7f90ad4970d9686637e8bb0beb
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vitalif/grive2
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk

define Package/grive2
	SECTION:=net
	CATEGORY:=Network
	SUBMENU:=Filesystem
	DEPENDS:=+libcurl +yajl +libstdcpp +libgcrypt +libexpat +libbfd \
		+boost-filesystem +boost-program_options +boost-regex +boost-test +boost-system
	TITLE:=This is the fork of original "Grive" (https://github.com/Grive/grive) Google Drive client
	URL:=https://github.com/vitalif/grive2
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/grive2/description
 This is the fork of original "Grive" (https://github.com/Grive/grive) Google Drive client
 with the support for the new Drive REST API and partial sync.
endef

ifneq ($(CONFIG_USE_UCLIBC),)
define Build/Prepare
	$(Build/Prepare/Default)
	$(SED) 's,find_package(BFD),#find_package(BFD),g' $(PKG_BUILD_DIR)/libgrive/CMakeLists.txt
endef
endif

define Package/grive2/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/grive \
		$(1)/opt/bin
	$(INSTALL_DIR) $(1)/opt/lib
endef

$(eval $(call BuildPackage,grive2))
