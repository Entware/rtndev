#
# Copyright (C) 2011-2021 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=cgdb
PKG_VERSION:=0.7.1
PKG_REV:=a68afd87a47b6e57b770cceac41ead127df99491
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/cgdb/cgdb.git
PKG_SOURCE_PROTO:=git
PKG_SOURCE_VERSION:=$(PKG_REV)
PKG_MIRROR_HASH:=1148e80db469f8f2d2170409001ff5e6719d582324465298974e2886d22d7a6c

PKG_FIXUP:=autoreconf

include $(INCLUDE_DIR)/package.mk

define Package/cgdb
	SECTION:=devel
	CATEGORY:=Development
	DEPENDS:=+gdb +libstdcpp
	TITLE:=GDB frontend
	URL:=https://cgdb.github.io/
	MAINTAINER:=Entware team, https://entware.net
endef

define Package/cgdb/description
 Console front-end to the GNU debugger.
endef

define Build/Prepare
	$(call Build/Prepare/Default)
	$(CP) $(PKG_BUILD_DIR)/configure.init $(PKG_BUILD_DIR)/configure.ac
	$(SED) "s|^AC_INIT(cgdb.*|AC_INIT(cgdb, $(PKG_VERSION))|g" $(PKG_BUILD_DIR)/configure.ac
endef

CONFIGURE_VARS += \
	ac_cv_file__dev_ptmx=yes \
	ac_cv_file__proc_self_status=yes \
	ac_cv_rl_version=8

define Package/cgdb/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/cgdb/cgdb $(1)/opt/bin
endef

$(eval $(call BuildPackage,cgdb))
