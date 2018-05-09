#
# Copyright (C) 2011-2018 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=encfs
PKG_VERSION:=1.9.2
PKG_REV:=514bfd34dab34a9b36670bb23928b2ad82e34432
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/vgough/encfs.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/cmake.mk
include $(INCLUDE_DIR)/nls.mk

define Package/encfs
	SECTION:=utils
	CATEGORY:=Utilities
	SUBMENU:=Filesystem
	DEPENDS:=+libopenssl +libstdcpp +fuse-utils +libatomic $(ICONV_DEPENDS) $(INTL_DEPENDS)
	TITLE:=encrypted filesystem in user-space
	URL:=http://www.arg0.net/#!encfs/c1awt
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/encfs/description
 EncFS provides an encrypted filesystem in user-space. It runs without any
 special permissions and uses the FUSE library module to provide the filesystem
 interface.
endef

TARGET_LDFLAGS += -lpthread -latomic -lintl

TARGET_CXXFLAGS += -std=c++0x

TARGET_CFLAGS += \
	-I$(STAGING_DIR)/opt/include \

define Package/encfs/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/encfs.bin $(1)/opt/bin/encfs
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/encfssh $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/encfsctl $(1)/opt/bin
endef

$(eval $(call BuildPackage,encfs))
