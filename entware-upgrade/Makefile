#
# Copyright (C) 2017-2019 Entware
#
# This is free software, licensed under the GNU General Public License v2.
# See /LICENSE for more information.
#
# This is the same package as entware-opt, it does not install busybox. It makes several symlinks instead of it!
# /opt/... folder order in /opt/etc/profile is different, /opt folders are the last in PATH
# This package is a replacement of entware-opt for asuswrt firmware


include $(TOPDIR)/rules.mk

PKG_NAME:=entware-upgrade
PKG_VERSION:=1.0
PKG_RELEASE:=1

include $(INCLUDE_DIR)/package.mk

define Package/entware-upgrade
	SECTION:=base
	CATEGORY:=Base system
	TITLE:=Entware upgrade package
	MAINTAINER:=Entware team, https://entware.net
	PKGARCH:=all
endef

define Package/entware-upgrade/description
 Helper package to upgrade Entware for future usage. Currently used to upgrade armv7soft (2.3.36) to the new codebase.
endef

define Build/Prepare
endef

define Build/Configure
endef

define Build/Compile
endef

define Package/entware-upgrade/install
	#
endef

ifeq ($(CONFIG_TARGET_armv7soft),y)
define Package/entware-upgrade/postinst
#!/bin/sh
if [[ -f /sbin/ifconfig && ! -f /opt/sbin/ifconfig ]]; then
    ln -s /sbin/ifconfig /opt/sbin/ifconfig
fi
if [[ -f /sbin/route && ! -f /opt/sbin/route ]]; then
    ln -s /sbin/route /opt/sbin/route
fi
if [[ -f /sbin/ip && ! -f /opt/sbin/ip ]]; then
    ln -s /sbin/ip /opt/sbin/ip
fi
if [[ -f /bin/netstat && ! -f /opt/bin/netstat ]]; then
    ln -s /bin/netstat /opt/bin/netstat
fi
if [[ ! -f /opt/bin/sh ]]; then
    ln -s /bin/sh /opt/bin/sh
fi
if [[ ! -f /opt/bin/ash ]]; then
    ln -s /bin/ash /opt/bin/ash
fi
# now try create symlinks - it is a std installation
if [ -f /etc/passwd ]
then
    ln -sf /etc/passwd /opt/etc/passwd
fi
if [ -f /etc/group ]
then
    ln -sf /etc/group /opt/etc/group
fi
if [ -f /etc/shells ]
then
    ln -sf /etc/shells /opt/etc/shells
fi
if [ -f /etc/shadow ]
then
    ln -sf /etc/shadow /opt/etc/shadow
fi
if [ -f /etc/gshadow ]
then
    ln -sf /etc/gshadow /opt/etc/gshadow
fi
if [ -f /etc/localtime ]
then
    ln -sf /etc/localtime /opt/etc/localtime
fi
endef
else
define Package/entware-upgrade/postinst
#!/bin/sh
echo "Upgrade operations are not required"
endef
endif
$(eval $(call BuildPackage,entware-upgrade))
