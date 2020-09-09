#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#

include $(TOPDIR)/rules.mk

PKG_NAME:=ltrace
PKG_VERSION:=0.7.9
PKG_RELEASE:=2

PKG_REV:=82c66409c7a93ca6ad2e4563ef030dfb7e6df4d4
PKG_SOURCE:=$(PKG_NAME)-$(PKG_VERSION).tar.bz2
PKG_SOURCE_SUBDIR:=$(PKG_NAME)-$(PKG_VERSION)
PKG_SOURCE_URL:=https://github.com/dkogan/ltrace
PKG_SOURCE_PROTO:=git

PKG_LICENSE:=GPL-2.0-only

PKG_FIXUP:=autoreconf
PKG_INSTALL:=1

include $(INCLUDE_DIR)/package.mk
include $(INCLUDE_DIR)/nls.mk

define Package/ltrace
  SECTION:=devel
  CATEGORY:=Development
  TITLE:=tracks runtime library calls in dynamically linked programs
  URL:=https://ltrace.org/
  DEPENDS:=+libelf +libdw +libstdcpp
endef

define Package/ltrace/description
 ltrace intercepts and records dynamic library calls which are called
by an executed process and the signals received by that process. It 
can also intercept and print the system calls executed by the program.
endef

CONFIGURE_VARS += \
	ac_cv_lib_selinux_security_get_boolean_active=no

define Package/ltrace/conffiles
/opt/share/ltrace
endef

define Package/ltrace/install
	$(INSTALL_DIR) $(1)/opt/bin
	$(INSTALL_BIN) $(PKG_INSTALL_DIR)/opt/bin/ltrace $(1)/opt/bin

	$(INSTALL_DIR) $(1)/opt/share/ltrace
	$(INSTALL_CONF) $(PKG_INSTALL_DIR)/opt/share/ltrace/*.conf $(1)/opt/share/ltrace
endef

$(eval $(call BuildPackage,ltrace))
